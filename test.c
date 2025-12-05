#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static int  is_duplicate(int *arr, int n, int value)
{
    int i;

    i = 0;
    while (i < n)
    {
        if (arr[i] == value)
            return (1);
        i++;
    }
    return (0);
}

static int  generate_unique(int *arr, int n)
{
    int value;
    int mod;

    mod = 1000000;
    value = rand() % mod;
    while (is_duplicate(arr, n, value))
        value = rand() % mod;
    return (value);
}

int main(void)
{
    int arr[500];
    int i;
    int value;

    i = 0;
    srand(time(NULL));

    while (i < 500)
    {
        value = generate_unique(arr, i);
        arr[i] = value;
        i++;
    }
    i = 0;

    while (i < 500)
    {
        printf("%d", arr[i]);
        if (i < 499)
            printf(" ");
        i++;
    }
    return (0);
}


////////////////////////////

#include "../include/push_swap.h"

/*
 * Helpers: копіювання верхніх n елементів із s->a або s->b у масив
 * і знаходження медиани (pivot) простим сортуванням вставками.
 */

static int *copy_top(int *src, int n)
{
	int *res;
	int i;

	res = malloc(sizeof(int) * n);
	if (!res) return (NULL);
	i = 0;
	while (i < n)
	{
		res[i] = src[i];
		i++;
	}
	return (res);
}

/* insertion sort (малий n, простий і надійний) */
static void	sort_int_array(int *arr, int n)
{
	int i;
	int j;
	int key;

	i = 1;
	while (i < n)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
		i++;
	}
}

static int	get_pivot_from_top(int *src, int n)
{
	int *tmp;
	int pivot;

	if (n <= 0) return (0);
	tmp = copy_top(src, n);
	if (!tmp) return (0);
	sort_int_array(tmp, n);
	pivot = tmp[n / 2];
	free(tmp);
	return (pivot);
}

/*
 * Малi сортування для невеликої кількості елементів на стеку A або B.
 * Ми оперуємо тільки верхніми елементами і використовуємо дозволені операції.
 *
 * sort_small_a: сортує верхні len елементи у A у зростаючому порядку.
 * sort_small_b: сортує верхні len елементи у B у спадному порядку
 *               (щоб після pa отримати зростаючий порядок в A).
 *
 * Ці функції написані явно для len = 1..3.
 */

static void	sort_small_a(t_stack *s, int len)
{
	if (len <= 1) return;
	if (len == 2)
	{
		if (s->a[0] > s->a[1])
			sa(s);
		return;
	}
	/* len == 3 */
	{
		int x = s->a[0];
		int y = s->a[1];
		int z = s->a[2];

		if (x > y && y < z && x < z)
			sa(s);
		else if (x > y && y > z && x > z)
		{
			sa(s);
			rra(s);
		}
		else if (x > y && y < z && x > z)
			ra(s);
		else if (x < y && y > z && x < z)
		{
			sa(s);
			ra(s);
		}
		else if (x < y && y > z && x > z)
			rra(s);
	}
}

static void	sort_small_b(t_stack *s, int len)
{
	if (len <= 1) return;
	if (len == 2)
	{
		if (s->b[0] < s->b[1]) /* на B ми хочемо спадний порядок, тож якщо 0<1, міняємо */
			sb(s);
		return;
	}
	/* len == 3: впорядкувати B так, щоб після pa, pa, pa у A було зростання */
	{
		int x = s->b[0];
		int y = s->b[1];
		int z = s->b[2];

		/* ми хочемо b[0] найбільшим, потім b[1], потім b[2] (спадний порядок) */
		if (x < y && y < z) /* x<y<z => z biggest -> bring z to top */
		{
			rb(s);
			sb(s);
			rrb(s);
			if (s->b[0] < s->b[1]) sb(s);
		}
		else if (x < y && y > z && x < z)
		{
			rrb(s);
			if (s->b[0] < s->b[1]) sb(s);
		}
		else if (x < y && y > z && x > z)
		{
			if (s->b[0] < s->b[1]) sb(s);
		}
		else if (x > y && y < z && x < z)
		{
			rb(s);
			if (s->b[0] < s->b[1]) sb(s);
			rrb(s);
		}
		else if (x > y && y < z && x > z)
		{
			if (s->b[0] < s->b[1]) sb(s);
			rb(s);
			if (s->b[0] < s->b[1]) sb(s);
			rrb(s);
		}
	}
}

/*
 * quicksort-like functions:
 * - quicksort_a: розбиває верхні len елементів A по pivot, pushes <= pivot в B,
 *                рекурсивно сортує ліву та праву частини.
 * - quicksort_b: розбиває верхні len елементів B по pivot, pushes > pivot в A,
 *                рекурсивно сортує B та повертає на A.
 *
 * У реалізації ми прагнемо мінімізувати кількість rot, повертаючи rra/rrb
 * для відкату тимчасових rot після partition.
 */

static void	quicksort_b(t_stack *s, int len); /* forward */

static void	quicksort_a(t_stack *s, int len)
{
	int pivot;
	int pushed;
	int rotated;
	int i;
	int curr;

	if (len <= 3)
	{
		sort_small_a(s, len);
		return ;
	}
	pivot = get_pivot_from_top(s->a, len);
	pushed = 0;
	rotated = 0;
	i = 0;
	curr = len;
	while (i < curr)
	{
		if (s->a[0] <= pivot)
		{
			pb(s);
			pushed++;
		}
		else
		{
			ra(s);
			rotated++;
		}
		i++;
	}
	/* відкотимо обертання, щоб відновити порядок в тих що лишились в A */
	while (rotated-- > 0)
		rra(s);

	/* рекурсивно сортуємо частину в A (елементи > pivot) */
	quicksort_a(s, len - pushed);

	/* сортуємо частину в B (елементи <= pivot) і повертаємо їх в A */
	quicksort_b(s, pushed);

	/* після сортування B — всі ці pushed елементи потраплять в A (через pa) */
	/* але quicksort_b сам повинен виконати pa необхідну кількість разів */
}

static void	quicksort_b(t_stack *s, int len)
{
	int pivot;
	int pushed;
	int rotated;
	int i;
	int curr;

	if (len <= 0) return ;
	if (len <= 3)
	{
		sort_small_b(s, len);
		/* після того як B впорядкований у спадному порядку, перемістимо назад в A */
		while (len-- > 0)
			pa(s);
		return ;
	}
	pivot = get_pivot_from_top(s->b, len);
	pushed = 0; /* кількість елементів, які перекинули в A ( > pivot ) */
	rotated = 0;
	i = 0;
	curr = len;
	while (i < curr)
	{
		if (s->b[0] > pivot)
		{
			pa(s);
			pushed++;
		}
		else
		{
			rb(s);
			rotated++;
		}
		i++;
	}
	/* відкотимо обертання на B */
	while (rotated-- > 0)
		rrb(s);

	/* тепер у A знаходяться pushed елементів (вгорі), вони можуть бути не в фінальному порядку */
	/* Сортуємо верхню частину A (це елементи > pivot), кількість = pushed */
	quicksort_a(s, pushed);

	/* Рекурсивно сортуємо залишок B (елементи <= pivot), і перенесемо їх назад */
	quicksort_b(s, len - pushed);
	/* Після цього всі елементи B (ті що <= pivot) будуть переміщені назад в A */
}

/*
 * Публічний інтерфейс (залишаємо ім'я radial_with_ops щоб не чіпати решту проекту)
 */
void	radix_with_ops(t_stack *s)
{
	quicksort_a(s, s->size_a);
}
