import requests

def control_light(choice):
    url = f"https://ny3.blynk.cloud/external/api/update?token=10qHSXj4L1k_CwFgO4PuH8KElGy1jHOj&d8={choice}"
    response = requests.get(url)

    if response.status_code == 200:
        print("Request sent successfully!")
        print("Response:", response.text)
    else:
        print("Error occurred while sending the request.")

def main():
    light_choice = int(input("Enter 1 to turn the light on or 0 to turn it off: "))
    control_light(light_choice)

if __name__ == "__main__":
    main()
