package main

import (
	"errors"
	"fmt"
)

func f1(arg int) (int, error) {
	if arg == 24 {
		return -1, errors.New("Can not running when arg equals 24")
	}
	return arg + 3, nil
}

type argError struct {
	arg  int
	prob string
}

func (e *argError) Error() string {
	return fmt.Sprintf("%s----%d", e.prob, e.arg)
}

func f2(arg int) (int, error) {
	if arg == 24 {
		return arg, &argError{arg: arg, prob: "arg 不能为24 异常"}
	}
	return arg + 3, nil
}

func main() {
	a := func() int {
		return 5
	}
	fmt.Println(a())
	for _, i := range []int{30, 24} {
		if r, e := f1(i); e == nil {
			fmt.Println("f1 field =", r)
		} else {
			fmt.Println("发生错误！", e)
		}
	}
	for _, i := range []int{30, 24} {
		if r, e := f2(i); e == nil {
			fmt.Println("f1 field =", r)
		} else {
			fmt.Println("发生错误！", e)
		}
	}
	_, e := f2(24)
	if ae, ok := e.(*argError); ok {
		fmt.Println(ae)
	}
}
