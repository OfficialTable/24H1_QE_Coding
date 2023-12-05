class Solution(object):
    def wordPattern(self, pattern, s):
        """
        :type pattern: str
        :type s: str
        :rtype: bool
        """
        words = s.split()

        if len(pattern) != len(words):
            return False #이 부분 없으면 wrong

        char_to_word = {}
        word_to_char = {}

        for char, word in zip(pattern, words):
            if char in char_to_word:
                if char_to_word[char] != word:
                    return False
            else:
                char_to_word[char] = word
            
            if word in word_to_char:
                if word_to_char[word] != char:
                    return False
            else:
                word_to_char[word] = char
        return True


   # 구현 안되던 코드
        # word_dict = {}
        # words_list = s.split()

        # for i in range(len(pattern)):
        #     if pattern[i] not in word_dict : 
        #         word_dict[pattern[i]] = words_list[i]
        # for i in range(len(pattern)):
        #     if word_dict[pattern[i]] != words_list[i]:
        #         return False
        # return True