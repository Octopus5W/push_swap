int int_before(int list[], int index, int size)
{
	if (index == 0)
		return (list[size - 1]);
	else
		return (list[index - 1]);
}
int int_after(int list[], int index, int size)
{
	if (index == size - 1)
		return (list[0]);
	else
		return (list[index + 1]);
}