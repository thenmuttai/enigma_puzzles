// problem : https://leetcode.com/problems/baseball-game
// time complexity  -> O(N)
// space complexity -> O(N)
int calPoints(char** operations, int operationsSize) {
    // allocate memory to an array to store the scores
    int *scores = malloc(operationsSize * sizeof(int));
    int score_cnt = 0;

    for (int i = 0; i < operationsSize; i++) {
        // try to conver the str to int, if conversion fails then it's
        // a operation else it's a record value
        int score = atoi(operations[i]);

        if (score) {
            scores[score_cnt++] = score;
            continue;
        }

        switch (operations[i][0]) {
            case '+':
                scores[score_cnt++] = scores[score_cnt - 1] + scores[score_cnt - 2];
                break;
            case 'D':
                scores[score_cnt++] = 2 * scores[score_cnt - 1];
                break;
            case 'C':
                score_cnt--;
        }
    }

    // calculate the sum of all the scores
    int sum = 0;
    for (int i = 0; i < score_cnt; i++) sum += scores[i];

    return sum;
}
