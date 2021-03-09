package com.kklll.learn.algorithm.leetcode;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * @ClassName CombinationSum
 * @Deacription 39. 组合总和   https://leetcode-cn.com/problems/combination-sum/
 * @Author DeepBlue
 * @Date 2021/3/7 16:23
 * @Version 1.0
 **/
public class CombinationSum {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> res = new ArrayList<>();
        ArrayDeque<Integer> path = new ArrayDeque<>();
        Arrays.sort(candidates);
        dfs(candidates, target, 0, path, res);
        return res;
    }

    public void dfs(int[] candidates, int target, int begin, ArrayDeque<Integer> path, List<List<Integer>> res) {
        if (target == 0) {
            res.add(new ArrayList<>(path));
            return;
        }
        for (int i = begin; i < candidates.length; i++) {
            if (candidates[i] > target) {
                break;
            }
            path.addLast(candidates[i]);
            dfs(candidates, target-candidates[i], i, path, res);
            path.removeLast();
        }
    }
}
