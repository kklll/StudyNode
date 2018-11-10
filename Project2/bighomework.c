//
////帮同学写的c语言大作业
////编译环境vs2010,如果有bug的话请指出。
////转载请注明出处，谢谢。
//
//#include<stdio.h>
//#include <time.h>
//#include <string.h>
//#include<stdlib.h>
//
//typedef struct _hjz {
//	int year;
//	int month;
//	int day;
//	int reserved;
//} hjz;
//unsigned int lunar200y[199] = {
//	0x04AE53,0x0A5748,0x5526BD,0x0D2650,0x0D9544,0x46AAB9,0x056A4D,0x09AD42,0x24AEB6,0x04AE4A,/*1901-1910*/
//	0x6A4DBE,0x0A4D52,0x0D2546,0x5D52BA,0x0B544E,0x0D6A43,0x296D37,0x095B4B,0x749BC1,0x049754,/*1911-1920*/
//	0x0A4B48,0x5B25BC,0x06A550,0x06D445,0x4ADAB8,0x02B64D,0x095742,0x2497B7,0x04974A,0x664B3E,/*1921-1930*/
//	0x0D4A51,0x0EA546,0x56D4BA,0x05AD4E,0x02B644,0x393738,0x092E4B,0x7C96BF,0x0C9553,0x0D4A48,/*1931-1940*/
//	0x6DA53B,0x0B554F,0x056A45,0x4AADB9,0x025D4D,0x092D42,0x2C95B6,0x0A954A,0x7B4ABD,0x06CA51,/*1941-1950*/
//	0x0B5546,0x555ABB,0x04DA4E,0x0A5B43,0x352BB8,0x052B4C,0x8A953F,0x0E9552,0x06AA48,0x6AD53C,/*1951-1960*/
//	0x0AB54F,0x04B645,0x4A5739,0x0A574D,0x052642,0x3E9335,0x0D9549,0x75AABE,0x056A51,0x096D46,/*1961-1970*/
//	0x54AEBB,0x04AD4F,0x0A4D43,0x4D26B7,0x0D254B,0x8D52BF,0x0B5452,0x0B6A47,0x696D3C,0x095B50,/*1971-1980*/
//	0x049B45,0x4A4BB9,0x0A4B4D,0xAB25C2,0x06A554,0x06D449,0x6ADA3D,0x0AB651,0x093746,0x5497BB,/*1981-1990*/
//	0x04974F,0x064B44,0x36A537,0x0EA54A,0x86B2BF,0x05AC53,0x0AB647,0x5936BC,0x092E50,0x0C9645,/*1991-2000*/
//	0x4D4AB8,0x0D4A4C,0x0DA541,0x25AAB6,0x056A49,0x7AADBD,0x025D52,0x092D47,0x5C95BA,0x0A954E,/*2001-2010*/
//	0x0B4A43,0x4B5537,0x0AD54A,0x955ABF,0x04BA53,0x0A5B48,0x652BBC,0x052B50,0x0A9345,0x474AB9,/*2011-2020*/
//	0x06AA4C,0x0AD541,0x24DAB6,0x04B64A,0x69573D,0x0A4E51,0x0D2646,0x5E933A,0x0D534D,0x05AA43,/*2021-2030*/
//	0x36B537,0x096D4B,0xB4AEBF,0x04AD53,0x0A4D48,0x6D25BC,0x0D254F,0x0D5244,0x5DAA38,0x0B5A4C,/*2031-2040*/
//	0x056D41,0x24ADB6,0x049B4A,0x7A4BBE,0x0A4B51,0x0AA546,0x5B52BA,0x06D24E,0x0ADA42,0x355B37,/*2041-2050*/
//	0x09374B,0x8497C1,0x049753,0x064B48,0x66A53C,0x0EA54F,0x06B244,0x4AB638,0x0AAE4C,0x092E42,/*2051-2060*/
//	0x3C9735,0x0C9649,0x7D4ABD,0x0D4A51,0x0DA545,0x55AABA,0x056A4E,0x0A6D43,0x452EB7,0x052D4B,/*2061-2070*/
//	0x8A95BF,0x0A9553,0x0B4A47,0x6B553B,0x0AD54F,0x055A45,0x4A5D38,0x0A5B4C,0x052B42,0x3A93B6,/*2071-2080*/
//	0x069349,0x7729BD,0x06AA51,0x0AD546,0x54DABA,0x04B64E,0x0A5743,0x452738,0x0D264A,0x8E933E,/*2081-2090*/
//	0x0D5252,0x0DAA47,0x66B53B,0x056D4F,0x04AE45,0x4A4EB9,0x0A4D4C,0x0D1541,0x2D92B5          /*2091-2099*/
//};
//
//int monthTotal[13] = { 0,31,59,90,120,151,181,212,243,273,304,334,365 };
//void function_1();
//void function_2();
//void function_3();
//int function_4();
//void function_5();
//void function_6();
//void yueli(int y, int m, int d);
//int getweek(int year, int month);
//int isleap(int year);
//int LunarCalendar(int year, int month, int day);
//hjz toLunar(hjz solar);
//hjz toSolar(hjz lunar);
//int main()
//{
//	int biaozhi = 1;
//	printf("本程序有6个功能：\n");
//	printf("1:输出月历\n");
//	printf("2:输入任意年月日，计算这一天是这一年的第几天\n");
//	printf("3:输入任意年月日，计算这一天为星期几\n");
//	printf("4:输入任意年月日，计算这一天为农历几月几日（支持1901--2099年）\n");
//	printf("5:输入任意年月日，输出最近的节假日及间隔天数\n");
//	printf("6:输入某个人的生日，输出年（天）龄\n");
//	printf("如果退出请输入0  \n");
//	printf("请输入选择的功能:(功能序号)\n");
//	for (; biaozhi != 0;)
//	{
//		scanf_s("%d", &biaozhi);
//		switch (biaozhi)
//		{
//		case 1:function_1(); break; case 2:function_2(); break; case 3:function_3(); break; case 4:function_4(); break;
//		case 5:function_5(); break; case 6:function_6(); break;
//		}
//	}
//	return 0;
//}
//
//void function_1()
//{
//	int y, m, d, week, i;
//	int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
//	printf("请输入年月日：（格式为：2018-1-1）\n");
//	scanf_s("%d-%d-%d", &y, &m, &d);
//	printf("=====================\n");
//	printf(" 一 二 三 四 五 六 日\n");
//	week = getweek(y, m);
//	//printf("%d",week);
//	if (week == 0)
//		week = 7;
//	for (i = 1; i < week; i++)
//	{
//		printf("   ");
//	}
//	if (isleap(y))
//		month[1] = 29;
//	for (i = 1; i <= month[m - 1]; i++)
//	{
//		printf("%3d", i);
//		if ((i + week - 1) % 7 == 0)
//			printf("\n");
//	}
//	printf("\n=====================\n");
//	printf("请再次输入要执行的程序（或输入0结束）：");
//}
//void function_2()
//{
//	int sum, i, m, y, d;
//	int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
//	printf("请输入年月日：（格式为：2018-1-1）\n");
//	scanf_s("%d-%d-%d", &y, &m, &d);
//	if (isleap(y))
//		month[1] = 29;
//	sum = 0;
//	for (i = 0; i < m - 1; i++)
//	{
//		sum += month[i];
//	}
//	sum = sum + d;
//	printf("这一天是这一年的第%d天\n", sum);
//	printf("请再次输入要执行的程序（或输入0结束）：");
//}
//void function_3()
//{
//	int y, m, d, thisweek, week;
//	printf("请输入年月日：（格式为：2018-1-1）\n");
//	scanf_s("%d-%d-%d", &y, &m, &d);
//	week = getweek(y, m);
//	thisweek = (week + d - 1) % 7;
//	switch (thisweek)
//	{
//	case 1:printf("这一天为周一\n"); break; case 2:printf("这一天为周二\n"); break; case 3:printf("这一天为周三\n"); break;
//	case 4:printf("这一天为周四\n"); break; case 5:printf("这一天为周五\n"); break; case 6:printf("这一天为周六\n"); break;
//	case 0:printf("这一天为周日\n"); break;
//	}
//	printf("请再次输入要执行的程序（或输入0结束）：");
//}
//int function_4()
//{
//	const char *ChDay[] = { "*","初一","初二","初三","初四","初五",
//		"初六","初七","初八","初九","初十",
//		"十一","十二","十三","十四","十五",
//		"十六","十七","十八","十九","二十",
//		"廿一","廿二","廿三","廿四","廿五",
//		"廿六","廿七","廿八","廿九","三十" };
//	const char *ChMonth[] = { "*","正","二","三","四","五","六","七","八","九","十","十一","腊" };
//	char str[13] = "";
//	hjz osolar;
//	hjz lunar;
//	printf("请输入年月日：（格式为：2018-1-1）\n");
//	scanf_s("%d-%d-%d", &osolar.year, &osolar.month, &osolar.day);
//	lunar = toLunar(osolar);
//	printf("转换农历为 %d-%d-%d\n", lunar.year, lunar.month, lunar.day);
//	printf("请再次输入要执行的程序（或输入0结束）：");
//	return 0;
//}
//void function_5()
//{
//	const char *ChDay[] = { "*","初一","初二","初三","初四","初五",
//		"初六","初七","初八","初九","初十",
//		"十一","十二","十三","十四","十五",
//		"十六","十七","十八","十九","二十",
//		"廿一","廿二","廿三","廿四","廿五",
//		"廿六","廿七","廿八","廿九","三十" };
//	const char *ChMonth[] = { "*","正","二","三","四","五","六","七","八","九","十","十一","腊" };
//	int year, month_1, day, reserved;
//	char str[13] = "";
//	int y, m, d, i;
//	int xinnian_dis = 0, laodong_dis = 0, guoqing_dis = 0, qingming_dis = 0, duanwu_dis = 0, zhongqiu_dis = 0, chunjie_dis = 0;
//	int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
//	hjz chunjieyangli;
//	hjz chunjieyinli = {
//		year = 2018,
//		month_1 = 1,
//		day = 1,
//		reserved = 0//1表示闰月,0表示平月
//	};
//	hjz qingmingyangli;
//	hjz qingmingyinli = {
//		year = 2018,
//		month_1 = 2 ,
//		day = 20 ,
//		reserved = 0//1表示闰月,0表示平月
//	};
//	hjz duanwuyangli;
//	hjz duanwuyinli = {
//		year = 2018,
//		month_1 = 5,
//		day = 5,
//		reserved = 0//1表示闰月,0表示平月
//	};
//	hjz zhongqiuyangli;
//	hjz zhongqiuyinli = {
//		year = 2018,
//		month_1 = 8,
//		day = 15,
//		reserved = 0//1表示闰月,0表示平月
//	};
//	printf("请输入年月日：（格式为：2018-1-1）\n");
//	scanf_s("%d-%d-%d", &y, &m, &d);
//	if (isleap(y))     //元旦距离
//		month[1] = 29;
//	for (i = m; i != 12; i++)
//		xinnian_dis += month[i];
//	xinnian_dis = xinnian_dis + month[m - 1] - d + 1;
//	printf("距离新年%d天\n", xinnian_dis);
//	if (m == 5)i = 6;
//	else i = m + 1;
//	for (; i != 5; i++)
//	{
//		if (i == 12)
//			i = 0;
//		laodong_dis += month[i];
//	}
//	laodong_dis = laodong_dis + month[m - 1] - d + 1;
//	printf("距离劳动节%d天\n", laodong_dis);
//	if (m == 10)i = 11;
//	else i = m + 1;
//	for (; i != 10; i++)
//	{
//		if (i == 12)
//			i = 0;
//		guoqing_dis += month[i];
//	}
//	guoqing_dis = guoqing_dis + month[m - 1] - d + 1;
//	printf("距离国庆节%d天\n", guoqing_dis);
//	chunjieyinli.year = y;
//	chunjieyangli = toSolar(chunjieyinli);
//	//printf("春节阳历: %d-%d-%d\n",chunjieyangli.year,chunjieyangli.month,chunjieyangli.day);
//	qingmingyinli.year = y;
//	qingmingyangli = toSolar(qingmingyinli);
//	//printf("清明阳历: %d-%d-%d\n",qingmingyangli.year,qingmingyangli.month,qingmingyangli.day);
//	duanwuyinli.year = y;
//	duanwuyangli = toSolar(duanwuyinli);
//	//printf("端午阳历: %d-%d-%d\n",duanwuyangli.year,duanwuyangli.month,duanwuyangli.day);
//	zhongqiuyinli.year = y;
//	zhongqiuyangli = toSolar(zhongqiuyinli);
//	//printf("中秋阳历: %d-%d-%d\n",zhongqiuyangli.year,zhongqiuyangli.month,zhongqiuyangli.day);
//	month[1] = 28;
//	if (isleap(chunjieyangli.year))     //春节距离
//		month[1] = 29;
//	if (m == chunjieyangli.month)i = chunjieyangli.month + 1;
//	else i = m + 1;
//	for (; i != chunjieyangli.month; i++)
//	{
//		if (i == 12)
//			i = 0;
//		chunjie_dis += month[i];
//	}
//	chunjie_dis = chunjie_dis + month[m - 1] - d + chunjieyangli.day;
//	if (chunjieyangli.month == m && d < chunjieyangli.day)
//	{
//		if (isleap(chunjieyangli.year))
//			chunjie_dis -= 366;
//		else chunjie_dis -= 365;
//	}
//	printf("距离春节%d天\n", chunjie_dis);
//	month[1] = 28;//清明距离
//	if (isleap(qingmingyangli.year))
//		month[1] = 29;
//	if (m == qingmingyangli.month)i = qingmingyangli.month + 1;
//	else i = m + 1;
//	for (; i != qingmingyangli.month; i++)
//	{
//		if (i == 12)
//			i = 0;
//		qingming_dis += month[i];
//	}
//	qingming_dis = qingming_dis + month[m - 1] - d + qingmingyangli.day;
//	if (qingmingyangli.month == m && d < qingmingyangli.day)
//	{
//		if (isleap(qingmingyangli.year))
//			qingming_dis = qingming_dis - 366;
//		else qingming_dis = qingming_dis - 365;
//	}
//	printf("距离清明%d天\n", qingming_dis);
//	month[1] = 28;
//	if (isleap(qingmingyangli.year))     //端午距离
//		month[1] = 29;
//	if (m == duanwuyangli.month)i = duanwuyangli.month + 1;
//	else i = m + 1;
//	for (; i != duanwuyangli.month; i++)
//	{
//		if (i == 12)
//			i = 0;
//		duanwu_dis += month[i];
//	}
//	duanwu_dis = duanwu_dis + month[m - 1] - d + duanwuyangli.day;
//	if (duanwuyangli.month == m && d < duanwuyangli.day)
//	{
//		if (isleap(duanwuyangli.year))
//			duanwu_dis -= 366;
//		else duanwu_dis -= 365;
//	}
//	printf("距离端午%d天\n", duanwu_dis);
//	month[1] = 28;
//	if (isleap(zhongqiuyangli.year))     //中秋距离
//		month[1] = 29;
//	if (m == zhongqiuyangli.month)i = zhongqiuyangli.month + 1;
//	else i = m + 1;
//	for (; i != zhongqiuyangli.month; i++)
//	{
//		if (i == 12)
//			i = 0;
//		zhongqiu_dis += month[i];
//	}
//	zhongqiu_dis = zhongqiu_dis + month[m - 1] - d + zhongqiuyangli.day;
//	if (zhongqiuyangli.month == m && d < zhongqiuyangli.day)
//	{
//		if (isleap(zhongqiuyangli.year))
//			zhongqiu_dis -= 366;
//		else zhongqiu_dis -= 365;
//	}
//	printf("距离中秋%d天\n", zhongqiu_dis);   //xinnian_dis,chunjie_dis,qingming_dis,laodong_dis,duanwu_dis,zhongqiu_dis,guoqing_dis
//	if (xinnian_dis < chunjie_dis&&xinnian_dis < qingming_dis&&xinnian_dis < laodong_dis&&xinnian_dis < duanwu_dis&&xinnian_dis < zhongqiu_dis&&xinnian_dis < guoqing_dis)
//		printf("距离最近的为：新年（元旦）还有：%d天\n", xinnian_dis);
//	if (chunjie_dis < xinnian_dis&&chunjie_dis < qingming_dis&&chunjie_dis < laodong_dis&&chunjie_dis < duanwu_dis&&chunjie_dis < zhongqiu_dis&&chunjie_dis < guoqing_dis)
//		printf("距离最近的为：春节 还有：%d天\n", chunjie_dis);
//	if (qingming_dis < xinnian_dis&&qingming_dis < chunjie_dis&&qingming_dis < laodong_dis&&qingming_dis < duanwu_dis&&qingming_dis < zhongqiu_dis&&qingming_dis < guoqing_dis)
//		printf("距离最近的为：清明节 还有：%d天\n", qingming_dis);
//	if (laodong_dis < xinnian_dis&&laodong_dis < chunjie_dis&&laodong_dis < qingming_dis&&laodong_dis < duanwu_dis&&laodong_dis < zhongqiu_dis&&laodong_dis < guoqing_dis)
//		printf("距离最近的为：劳动节 还有：%d天\n", laodong_dis);
//	if (duanwu_dis < xinnian_dis&&duanwu_dis < qingming_dis&&duanwu_dis < laodong_dis&&duanwu_dis < chunjie_dis&&duanwu_dis < zhongqiu_dis&&duanwu_dis < guoqing_dis)
//		printf("距离最近的为：端午节 还有：%d天\n", duanwu_dis);
//	if (zhongqiu_dis < xinnian_dis&&zhongqiu_dis < qingming_dis&&zhongqiu_dis < laodong_dis&&zhongqiu_dis < duanwu_dis&&zhongqiu_dis < chunjie_dis&&zhongqiu_dis < guoqing_dis)
//		printf("距离最近的为：中秋节 还有：%d天\n", zhongqiu_dis);
//	if (guoqing_dis < xinnian_dis&&guoqing_dis < qingming_dis&&guoqing_dis < laodong_dis&&guoqing_dis < duanwu_dis&&guoqing_dis < zhongqiu_dis&&guoqing_dis < chunjie_dis)
//		printf("距离最近的为：国庆节  还有：%d天\n", guoqing_dis);
//	printf("请再次输入要执行的程序（或输入0结束）：");
//}
//void function_6()
//{
//	int y, m, d, age, sumday, i;
//	int y_1, m_1, d_1;
//	int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
//	struct tm * lt;
//	time_t t;
//	time(&t);
//	lt = localtime(&t);
//	y = lt->tm_year + 1900;
//	m = lt->tm_mon;
//	d = lt->tm_mday;
//	printf("请输入出生年月日：（格式为：2018-1-1）\n");
//	scanf_s("%d-%d-%d", &y_1, &m_1, &d_1);
//	printf("今天为%d年%d月%d日\n", y, m, d);
//	age = y - y_1;
//	if (m <= m_1 && d <= d_1)
//		age -= 1;
//	printf("今年的年龄为:%d\n", age);
//	sumday = 0;
//	if (isleap(y_1))
//		month[1] = 29;
//	for (i = m_1; i < 12; i++)
//		sumday += month[i];
//	sumday = sumday + month[m_1 - 1] - d_1;
//	month[1] = 28;
//	for (i = y_1 + 1; i < y; i++)
//	{
//		if (isleap(i))
//			sumday += 366;
//		else
//			sumday += 365;
//	}
//	if (isleap(y))
//		month[1] = 29;
//	for (i = 0; i <= m - 1; i++)
//		sumday += month[i];
//	sumday = sumday + d - 1;
//	printf("截至当前时间你的天龄为%d\n", sumday);
//	printf("请再次输入要执行的程序（或输入0结束）：");
//}
//
//int getweek(int year, int month)
//{
//	int m[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
//	int day = 0, week, i;
//	switch (month)
//	{
//	case 1:
//		day = 1;
//		break;
//	case 2:
//		day = m[0] + 1;
//		break;
//	case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10: case 11: case 12:
//		if (isleap(year))
//			m[1] = 29;
//		for (i = 0; i < month - 1; i++)
//		{
//			day = day + m[i];
//		}
//		day = day + 1;
//		break;
//	}
//	week = ((year - 1) + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400 + day) % 7;
//	return week;
//}
//int isleap(int year)
//{
//	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
//		return 1;
//	else
//		return 0;
//}
//hjz toLunar(hjz solar) {
//	int year = solar.year,
//		month = solar.month,
//		day = solar.day;
//	int bySpring, bySolar, daysPerMonth;
//	int index, flag;
//	hjz lunar;
//
//	//bySpring 记录春节离当年元旦的天数。
//	//bySolar 记录阳历日离当年元旦的天数。
//	if (((lunar200y[year - 1901] & 0x0060) >> 5) == 1)
//		bySpring = (lunar200y[year - 1901] & 0x001F) - 1;
//	else
//		bySpring = (lunar200y[year - 1901] & 0x001F) - 1 + 31;
//	bySolar = monthTotal[month - 1] + day - 1;
//	if ((!(year % 4)) && (month > 2))
//		bySolar++;
//
//	//daysPerMonth记录大小月的天数 29 或30
//	//index 记录从哪个月开始来计算。
//	//flag 是用来对闰月的特殊处理。
//
//	//判断阳历日在春节前还是春节后
//	if (bySolar >= bySpring) {//阳历日在春节后（含春节那天）
//		bySolar -= bySpring;
//		month = 1;
//		index = 1;
//		flag = 0;
//		if ((lunar200y[year - 1901] & (0x80000 >> (index - 1))) == 0)
//			daysPerMonth = 29;
//		else
//			daysPerMonth = 30;
//		while (bySolar >= daysPerMonth) {
//			bySolar -= daysPerMonth;
//			index++;
//			if (month == ((lunar200y[year - 1901] & 0xF00000) >> 20)) {
//				flag = ~flag;
//				if (flag == 0)
//					month++;
//			}
//			else
//				month++;
//			if ((lunar200y[year - 1901] & (0x80000 >> (index - 1))) == 0)
//				daysPerMonth = 29;
//			else
//				daysPerMonth = 30;
//		}
//		day = bySolar + 1;
//	}
//	else {//阳历日在春节前
//		bySpring -= bySolar;
//		year--;
//		month = 12;
//		if (((lunar200y[year - 1901] & 0xF00000) >> 20) == 0)
//			index = 12;
//		else
//			index = 13;
//		flag = 0;
//		if ((lunar200y[year - 1901] & (0x80000 >> (index - 1))) == 0)
//			daysPerMonth = 29;
//		else
//			daysPerMonth = 30;
//		while (bySpring > daysPerMonth) {
//			bySpring -= daysPerMonth;
//			index--;
//			if (flag == 0)
//				month--;
//			if (month == ((lunar200y[year - 1901] & 0xF00000) >> 20))
//				flag = ~flag;
//			if ((lunar200y[year - 1901] & (0x80000 >> (index - 1))) == 0)
//				daysPerMonth = 29;
//			else
//				daysPerMonth = 30;
//		}
//
//		day = daysPerMonth - bySpring + 1;
//	}
//	lunar.day = day;
//	lunar.month = month;
//	lunar.year = year;
//	if (month == ((lunar200y[year - 1901] & 0xF00000) >> 20))
//		lunar.reserved = 1;
//	else
//		lunar.reserved = 0;
//	return lunar;
//}
//hjz toSolar(hjz lunar) {
//	int year = lunar.year,
//		month = lunar.month,
//		day = lunar.day;
//	int byNow, xMonth, i;
//	hjz solar;
//	byNow = (lunar200y[year - 1901] & 0x001F) - 1;
//	if (((lunar200y[year - 1901] & 0x0060) >> 5) == 2)
//		byNow += 31;
//	for (i = 1; i < month; i++) {
//		if ((lunar200y[year - 1901] & (0x80000 >> (i - 1))) == 0) {
//			byNow += 29;
//		}
//		else
//			byNow += 30;
//	}
//	byNow += day;
//	xMonth = (lunar200y[year - 1901] & 0xf00000) >> 20;
//	if (xMonth != 0) {
//		if (month > xMonth
//			|| (month == xMonth && lunar.reserved == 1)) {
//			if ((lunar200y[year - 1901] & (0x80000 >> (month - 1))) == 0)
//				byNow += 29;
//			else
//				byNow += 30;
//		}
//	}
//	if (byNow > 366
//		|| (year % 4 != 0 && byNow == 365)) {
//		year += 1;
//		if (year % 4 == 0)
//			byNow -= 366;
//		else
//			byNow -= 365;
//	}
//	for (i = 1; i <= 13; i++) {
//		if (monthTotal[i] >= byNow) {
//			month = i;
//			break;
//		}
//	}
//	solar.day = byNow - monthTotal[month - 1];
//	solar.month = month;
//	solar.year = year;
//
//	return solar;
//}