from typing import List, TypeVar, Generic

T = TypeVar('T')


class Shelf(Generic[T]):
    def __init__(self):
        self.items: List[T] = []

    def place_item(self, item: T):
        self.items.append(item)

    def take_item(self, index: int):
        if self.items:
            return self.items.pop(index)
        else:
            print("shelf is empty")

    def find_min(self):
        if self.items:
            return min(self.items)
        else:
            print("shelf is empty")

    def delete_items(self):
        if self.items:
            return self.items.clear()
        else:
            print("shelf is empty")

    def show_items(self):
        print(self.items)


def main():
    shelf = Shelf[str]()
    shelf.place_item("23")
    shelf.place_item("2")
    shelf.place_item("544")

    shelf.show_items()
    print(shelf.find_min())

    print(shelf.take_item(2))
    shelf.show_items()

if __name__ == '__main__':
    main()
