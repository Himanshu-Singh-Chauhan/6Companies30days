```c++
class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        int cows = 0;

        map<char, int> secretmp;
        map<char, int> guessmp;

        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) bulls++;
            else {
                secretmp[secret[i]]++;
                guessmp[guess[i]]++;
            }
        }

        for (auto kv: secretmp) {
            if (guessmp.count(kv.first)) {
                cows += min(kv.second, guessmp[kv.first]);
            }
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
```

[Maximum sum of i*arr\[i\] among all rotations of given array | GFG | Algorithm Explanation by alGOds - YouTube](https://www.youtube.com/watch?v=3YNs_Ggqb-Q)

<img src="C:\Users\S\Desktop\6Companies30days\resources\bulls and cows.png" alt="image-20230102112140498" style="zoom:50%;" />