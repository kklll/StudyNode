package main

import (
	"encoding/json"
	"fmt"
	"os"
)

type response1 struct {
	Page   int
	Fruits []string
}
type response2 struct {
	Page   int      `json:"page"`
	Fruits []string `json:"fruits"`
}

func main() {
	boB, _ := json.Marshal(true)
	fmt.Println(string(boB))
	intB, _ := json.Marshal(1)
	fmt.Println(string(intB))
	fltB, _ := json.Marshal(2.34)
	fmt.Println(string(fltB))
	strB, _ := json.Marshal("测试信息")
	fmt.Println(string(strB))
	listB, _ := json.Marshal([]string{"apple", "peach", "pear"})
	fmt.Println(string(listB))
	mapD, _ := json.Marshal(map[string]string{"apple": "ok", "pear": "no"})
	fmt.Println(string(mapD))
	resD := &response1{
		Page:   2,
		Fruits: []string{"苹果皮", "香蕉皮", "橘子皮"},
	}
	ress, _ := json.Marshal(resD)
	fmt.Println(string(ress))
	res2D := &response2{Page: 2, Fruits: []string{"apple", "banana", "pear"}}
	ress2, _ := json.Marshal(res2D)
	fmt.Println(string(ress2))

	bty := []byte(`{"num":6.13,"strs":["a","b"]}`)

	var data map[string]interface{}
	if err := json.Unmarshal(bty, &data); err != nil {
		panic(err)
	}
	fmt.Println(data)
	num := data["num"].(float64)
	fmt.Println(num)

	strs := data["strs"].([]interface{})
	str1 := strs[0].(string)
	fmt.Println(str1)

	str := `{"page": 1, "fruits": ["apple", "peach"]}`
	res := response2{}
	err := json.Unmarshal([]byte(str), &res)
	if err != nil {
		panic(err)
	}
	fmt.Println(res)
	fmt.Println(res.Fruits[0])
	enc := json.NewEncoder(os.Stdout)
	d := map[string]int{"apple": 5, "banana": 6}
	err2 := enc.Encode(d)
	if err2 != nil {
		return
	}
}
