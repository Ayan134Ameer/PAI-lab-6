def max_profit(prices):
    minimum = prices[0]
    profit = 0

    for i in prices:
        if i < minimum:
            minimum = i

        current_profit = i - minimum

        if current_profit > profit:
            profit = current_profit

    return profit


prices = [7,1,5,3,6,4]

print("Maximum profit:",max_profit(prices))