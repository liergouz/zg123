#include <npc.h>
#include <ansi.h>
#include <public.h>

inherit OFFICER;
// 函数：获取人物造型
int get_char_picid() { return 1289; }
// 函数：构造处理
void create()
{
        set_name("圣诞笨熊");
        setup();
}

void do_look(object who)
{
	object me=this_object();
	send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    打…打…打劫～把你们的IC、IP、IQ卡统统拿来！最重要的是圣诞礼物赶紧给我！",me->get_name()));
}



