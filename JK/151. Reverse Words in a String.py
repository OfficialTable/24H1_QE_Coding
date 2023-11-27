def reverseWords(s: str) -> str:
    
    words = s.split()

    reversed_words = reversed(words)

    reversed_string = ' '.join(reversed_words)

    return reversed_string