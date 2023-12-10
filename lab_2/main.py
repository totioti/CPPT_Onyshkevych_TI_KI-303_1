﻿class TV:
    def __init__(self, brand: str, price: float, screen_size: int):
        self.COLOUR = ("neutral", "warm", "white", "cool", "native")
        self.STATES = ("OFF", "ON")
        self.BASE_CHANNEL = 0
        self.BASE_VOLUME = 50

        self.brand = brand
        self.price = price
        self.screen_size = screen_size

        self.is_on = True
        self.volume = self.BASE_VOLUME
        self.scheme = self.COLOUR[0]
        self.current_channel = self.BASE_CHANNEL

    def tv_state(self) -> None:
        print(f"Turning off the {self.brand} TV...") if self.is_on else print(f"Turning on the {self.brand} TV...")

        self.is_on = not self.is_on

    def set_colour_scheme(self, scheme: str) -> None:
        self.scheme = scheme if scheme in self.COLOUR else self.COLOUR[0]

    def chanel_switch(self, channel: int) -> None:
        self.current_channel = channel if self.is_on else self.BASE_CHANNEL

        print(f"Changed to channel {self.current_channel}")

    def volume_control(self, volume: int) -> None:
        self.volume = volume if volume in range(100) else self.BASE_VOLUME

        print(f"Changed on {self.volume} dB")

    def __str__(self) -> str:
        return (f"Model: {self.brand}\n"
                f"Price: {self.price} $\n"
                f"Screen size: {self.screen_size} Inch \n"
                f"Power: {self.STATES[self.is_on]}\n"
                f"Channel: {self.current_channel}\n"
                f"Volume: {self.volume}")


def main():
    tv = TV("Samsung", 129.99, 55)
    tv.volume_control(90)
    tv.set_colour_scheme("warm")
    tv.chanel_switch(5)
    print(tv)

if __name__ == "__main__":
    main()