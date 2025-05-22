#include <iostream>
#include <vector>

int merge(std::vector<int>& vec, std::vector<int>& temp, int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = left;
    int inversion_counter = 0;
    while (i <= mid && j <= right)
    {
        if (vec[i] <= vec[j])
        {
            temp[k] = vec[i];
            i++;
        }
        else
        {
            temp[k] = vec[j];
            inversion_counter += (mid - i + 1);
            j++;
        }
        k++;
    }
    while (i <= mid)
    {
        temp[k] = vec[i];
        i++;
        k++;
    }
    while (j <= right)
    {
        temp[k] = vec[j];
        j++;
        k++;
    }
    for (i = left; i <= right; i++)
        vec[i] = temp[i];

    return inversion_counter;
}
int merge_and_count(std::vector<int>& vec, std::vector<int>& temp, int left, int right)
{
    if (left >= right)
        return 0;
    int mid = left + (right - left) / 2;
    int inv_count = merge_and_count(vec, temp, left, mid);
    inv_count += merge_and_count(vec, temp, mid + 1, right);
    inv_count += merge(vec, temp, left, mid, right);

    return inv_count;
}
int
main()
{
    std::vector<int> data = { 1, 5, 4, 8, 10, 2, 6, 9, 12, 11, 3, 7 };
    std::vector<int> temp(data.size());
    std::cout << "Array: ";
    for (int num : data)
        std::cout << num << " ";
    std::cout << "\n\n";
    int inv_count = merge_and_count(data, temp, 0, data.size() - 1);
    std::cout << "Array: ";
    for (int num : data)
        std::cout << num << " ";
    std::cout << "\nInversiones: " << inv_count << std::endl;

    return 0;
}