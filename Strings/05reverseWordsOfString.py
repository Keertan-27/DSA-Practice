def reverseWordsOfString(s):
    words = s.split()
    words.reverse()
    return " ".join(words)


if __name__ == "__main__":
    s = "the moon star"
    ans = reverseWordsOfString(s)
    print(ans)
