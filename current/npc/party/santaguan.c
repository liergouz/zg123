#include <npc.h>
#include <ansi.h>
#include <public.h>

inherit OFFICER;
// 函数：获取人物造型
int get_char_picid() { return 1291; }
// 函数：构造处理
void create()
{
        set_name("圣诞罐妖");
        setup();
}

void do_look(object who)
{
	object me=this_object();
	send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    罐子外面的人听着，你们已经被包围了，放下你们的武器，把所有的圣诞礼物丢进我的罐子里！哈哈哈哈～～",me->get_name()));
}



