def main():
    time = input("What time is it? ").lower().strip()
    time = convert(time)

    if time >= 7.0 and time <= 8.0:
        print("breakfast time")
    elif time >= 12.0 and time <= 13.0:
        print("lunch time")
    elif time >= 18.0 and time <= 19.0:
        print("dinner time")


def convert(time):
    hours, minutes = time.split(":")
    time_float = float(hours) + float(minutes)/60
    return time_float

if __name__ == "__main__":
    main()
