/*
 * @lc app=leetcode id=2326 lang=cpp
 *
 * [2326] Spiral Matrix IV
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include<bits/stdc++.h>

/*
 Time complexity: O(l*(m+n))
 Space complexity: O(1)
 l: size of the linked list
 m: number of rows
 n: number of columns
*/
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
class Solution {
public:
    vvi spiralMatrix(int m, int n, ListNode* head){
        int top=0,right=n-1,bottom=m-1,left=0;
        vvi ans(m,vi(n,-1));

        bool ok=left<=right && top<=bottom;
        ListNode* trav=head;
        while(trav&&ok){
            if(ok){
                for(int i=left;trav!=nullptr && i<=right;++i){
                    ans[top][i]=trav->val;
                    trav=trav->next;
                }
                top++;
                for(int i=top;trav!=nullptr && i<=bottom;++i){
                    ans[i][right]=trav->val;
                    trav=trav->next;
                }
                right--;
            }

            ok=left<=right && top<=bottom;
            if(ok){
                for(int i=right;trav!=nullptr && i>=left;--i){
                    ans[bottom][i]=trav->val;
                    trav=trav->next;
                }
                bottom--;
                for(int i=bottom;trav!=nullptr && i>=top;--i){
                    ans[i][left]=trav->val;
                    trav=trav->next;
                }
                left++;
            }
        }

        return ans;
    }
};
// @lc code=end

