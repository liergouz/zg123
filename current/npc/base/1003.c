
// 自动生成：/make/npc/make0002

#include <npc.h>
#include <cmd.h>

inherit OFFICER;

// 函数：小贩识别
int is_seller() { return 6; }

// 函数：获取人物造型
int get_char_picid() { return 5403; }

// 函数：构造处理
void create()
{
        set_name("药店老板");
	set_real_name("扁鹊");
        set_city_name("齐国");

        set_2( "good", ([
                "01" : "/item/91/9100",
                "02" : "/item/91/9101",
                "03" : "/item/91/9110",
                "04" : "/item/91/9111",
                "05" : "/item/stuff/0106",
        ]) );

        setup();
}
