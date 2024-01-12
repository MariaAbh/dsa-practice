def knapsack(values,weights,capacity):
    if len(values) == 0 or capacity == 0:
        return 0
    if weights[0] <= capacity:
        return max(
                values[0] + knapsack(values[1:],weights[1:],capacity-weights[0]),
                knapsack(values[1:],weights[1:],capacity)
                )
    else:
        return knapsack(values[1:],weights[1:],capacity)

values = [60,100,120]
weights = [10,20,30]
capacity = 50
print(knapsack(values,weights,capacity))
print('----------')
values = [10,20,30,40]
weights = [12,13,15,19]
capacity = 10
print(knapsack(values,weights,capacity))
