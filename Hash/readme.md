## Hash Function 

### Rolling hash
Tutorial: [Rolling hash | Rabin karp algorithm | Pattern searching](https://www.youtube.com/watch?v=BQ9E-2umSWc) cre: Techdose

### LPS & KMP Algorithm
Tutorial 1: [KMP Algorithm](https://www.youtube.com/watch?v=7YfmUxxRNwo)

Tutorial 2: [Knuth-Morris-Pratt algorithm (KMP) - Inside code](https://www.youtube.com/watch?v=M9azY7YyMqI)

``LPS - Longest Prefix Suffix``: we construct an LPS array, where each index i stores the length of the longest proper prefix of the substring ``str[0...i]`` that is also a suffix of the same substring  

```
def get_lps(s):
    lps = [0]*len(s)
    i=1; j=0
    while i < len(s):
        if s[i] == s[j]:
            lps[i] = j + 1
            j+=1; i+=1
        elif s[i] != s[j] and j > 0:
            j = lps[i-1]
        else: 
            lps[i] = 0
            i += 1
```