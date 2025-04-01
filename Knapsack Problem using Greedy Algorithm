def knapsack_greedy(items, capacity):
    items.sort(key=lambda x: x[1] / x[0], reverse=True)  # Sort by value/weight ratio
    total_value = 0
    knapsack = []

    for weight, value in items:
        if capacity >= weight:
            knapsack.append((weight, value))
            total_value += value
            capacity -= weight
        else:
            fraction = capacity / weight
            knapsack.append((weight * fraction, value * fraction))
            total_value += value * fraction
            break

    return total_value, knapsack

# Example usage
items = [(10, 60), (20, 100), (30, 120)]  # (weight, value)
capacity = 50
max_value, selected_items = knapsack_greedy(items, capacity)
print("Maximum value:", max_value)
print("Items selected:", selected_items)
