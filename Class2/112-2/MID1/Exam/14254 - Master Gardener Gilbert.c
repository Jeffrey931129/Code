#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MOD 998244353
typedef struct _Node {
    int val; // {0 ~ 9: number, -1: +, -2: -, -3: *}
    int ans;
    struct _Node *lc, *rc, *p;
} Node;
char expr[2200000] = {};
Node *tree[2200000] = {};
int h, t, n;
int idx = 0;

Node *build() {
    if(idx >= n) return NULL;
    Node *r = (Node *)malloc(sizeof(Node));
    tree[idx] = r;
    r->ans = -1, r->lc = r->rc = r->p = NULL;
    if(expr[idx] >= '0' && expr[idx] <= '9'){
        r->val = expr[idx] - '0';
        idx++;
    }
    else {
        if(expr[idx] == '+') r->val = -1;
        else if(expr[idx] == '-') r->val = -2;
        else r->val = -3;
        idx++;
        r->lc = build();
        r->rc = build();
        r->lc->p = r;
        r->rc->p = r;
    }
    return r;
}

int eval(Node *t) {
    if(t->ans != -1) {
        return t->ans;
    }
    if(t->val == -1) {
        return t->ans = ((1ll * eval(t->lc) + eval(t->rc)) % MOD + MOD) % MOD;
    }
    else if(t->val == -2) {
        return t->ans = ((1ll * eval(t->lc) - eval(t->rc)) % MOD + MOD) % MOD;
    }
    else if(t->val == -3) {
        return t->ans = ((1ll * eval(t->lc) * eval(t->rc)) % MOD + MOD) % MOD;
    }
    else {
        return t->ans = t->val;
    }
}

void reset(Node *t) {
    if(t == NULL) return;
    t->ans = -1;
    reset(t->p);
}

void swap(Node *a, Node *b) {
    int tmp = a->val;
    a->val = b->val;
    b->val = tmp;

    tmp = a->ans;
    a->ans = b->ans;
    b->ans = tmp;

    Node *tmp_node = a->lc;
    a->lc = b->lc;
    b->lc = tmp_node;

    tmp_node = a->rc;
    a->rc = b->rc;
    b->rc = tmp_node;

    reset(a->p);
    reset(b->p);
}

bool dfs(Node *now, Node *target) {
    if(now == NULL) return false;
    if(now == target) {
        return true;
    }
    else {
        return dfs(now->lc, target) || dfs(now->rc, target);
    }
}

bool check(Node *a, Node *b) {
    if(dfs(a, b) || dfs(b, a)) {
        return false;
    }
    else {
        return true;
    }
}

int max(int a, int b) {
    if(a > b) return a;
    return b;
}

signed main() {
    scanf("%d %d", &h, &t);
    scanf("%s", expr);
    n = (1 << (h + 1)) - 1;
    build();
    int ans = eval(tree[0]);
    if(t == 1) {
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                if(check(tree[i], tree[j])) {
                    swap(tree[i], tree[j]);
                    ans = max(ans, eval(tree[0]));
                    swap(tree[i], tree[j]);
                }
            }
        }
    }
    else {
        for(int i = 0; i < n; ++i) {
            if(tree[i]->lc != NULL && tree[i]->rc != NULL && tree[i]->val == -2) {
                swap(tree[i]->lc, tree[i]->rc);
                ans = max(ans, eval(tree[0]));
                swap(tree[i]->lc, tree[i]->rc);
            }
        }
    }
    printf("%d\n", ans);
}
