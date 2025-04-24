class ArchiveItem:
    def __init__(self, uid, title, year):
        self.uid = uid
        self.title = title
        self.year = year

    def __str__(self):
        return f"UID: {self.uid}, Title: {self.title}, Year: {self.year}"

    def __eq__(self, other):
        return self.uid == other.uid

    def is_recent(self, n):
        return (2025 - self.year) <= n


class Book(ArchiveItem):
    def __init__(self, uid, title, year, author, pages):
        super().__init__(uid, title, year)
        self.author = author
        self.pages = pages

    def __str__(self):
        return f"Book -> UID: {self.uid}, Title: {self.title}, Year: {self.year}, Author: {self.author}, Pages: {self.pages}"


class Article(ArchiveItem):
    def __init__(self, uid, title, year, journal, doi):
        super().__init__(uid, title, year)
        self.journal = journal
        self.doi = doi

    def __str__(self):
        return f"Article -> UID: {self.uid}, Title: {self.title}, Year: {self.year}, Journal: {self.journal}, DOI: {self.doi}"


class Podcast(ArchiveItem):
    def __init__(self, uid, title, year, host, duration):
        super().__init__(uid, title, year)
        self.host = host
        self.duration = duration

    def __str__(self):
        return f"Podcast -> UID: {self.uid}, Title: {self.title}, Year: {self.year}, Host: {self.host}, Duration: {self.duration} mins"


def save_to_file(items, filename):
    with open(filename, 'w') as file:
        for item in items:
            if isinstance(item, Book):
                line = f"Book,{item.uid},{item.title},{item.year},{item.author},{item.pages}\n"
            elif isinstance(item, Article):
                line = f"Article,{item.uid},{item.title},{item.year},{item.journal},{item.doi}\n"
            elif isinstance(item, Podcast):
                line = f"Podcast,{item.uid},{item.title},{item.year},{item.host},{item.duration}\n"
            file.write(line)


def load_from_file(filename):
    items = []
    with open(filename, 'r') as file:
        for line in file:
            parts = line.strip().split(',')
            type_ = parts[0]
            if type_ == "Book":
                _, uid, title, year, author, pages = parts
                items.append(Book(uid, title, int(year), author, int(pages)))
            elif type_ == "Article":
                _, uid, title, year, journal, doi = parts
                items.append(Article(uid, title, int(year), journal, doi))
            elif type_ == "Podcast":
                _, uid, title, year, host, duration = parts
                items.append(Podcast(uid, title, int(year), host, int(duration)))
    return items


if __name__ == "__main__":
    archive = [
        Book("B001", "Yapay Zeka", 2018, "Ahmet Yılmaz", 520),
        Book("B002", "Temiz Kod", 2021, "Mehmet Demir", 384),
        Article("A101", "Kuantum Hesaplama", 2023, "Bilim Dergisi", "10.1234/qc890"),
        Article("A102", "Etik ve Yapay Zeka", 2019, "Teknoloji Günlüğü", "10.5678/etik456"),
        Podcast("P301", "Tekno Sohbet", 2024, "Ayşe Kara", 50),
        Podcast("P302", "Yazılım Günlükleri", 2020, "Ali Veli", 40),
    ]

    save_to_file(archive, "archive.txt")
    loaded_archive = load_from_file("archive.txt")

    for item in loaded_archive:
        print(item)

    print("\nSon 5 yıldaki içerikler:")
    for item in loaded_archive:
        if item.is_recent(5):
            print(item)

    print("\nDOI'si '10.1234' ile başlayan makaleler:")
    for item in loaded_archive:
        if isinstance(item, Article) and item.doi.startswith("10.1234"):
            print(item)
