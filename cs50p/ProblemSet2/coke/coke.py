total_paid = 0
amount_due = 50
while(total_paid < 50):
    print("Amount Due:", amount_due)
    coin = int(input("Insert Coin: "))
    if(coin == 25 or coin == 10 or coin == 5):
        total_paid += coin
        amount_due -= coin

change_owed = total_paid - 50

print("Change Owed:", change_owed)
