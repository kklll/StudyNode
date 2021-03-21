package com.kklll.learn.algorithm.leetcode;

import java.util.HashMap;
import java.util.Map;

/**
 * @ClassName ParkingSystem
 * @Deacription 1603. 设计停车系统    https://leetcode-cn.com/problems/design-parking-system/
 * @Author DeepBlue
 * @Date 2021/3/19 11:52
 * @Version 1.0
 **/
class ParkingSystem {
    int[] map;

    public ParkingSystem(int big, int medium, int small) {
        map = new int[4];
        map[1] = big;
        map[2] = medium;
        map[3] = small;
    }

    public boolean addCar(int carType) {
        switch (carType) {
            case 1:
                return canAddCar(1);
            case 2:
                return canAddCar(2);
            case 3:
                return canAddCar(3);
        }
        return false;
    }

    private boolean canAddCar(int i) {
        if (map[i] > 0) {
            map[i]--;
            return true;
        } else {
            return false;
        }
    }
}