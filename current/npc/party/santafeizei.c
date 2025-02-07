#include <npc.h>
#include <ansi.h>
#include <public.h>

inherit OFFICER;
// 函数：获取人物造型
int get_char_picid() { return 1290; }
// 函数：构造处理
void create()
{
        set_name("圣诞飞贼");
        setup();
}

void do_look(object who)
{
	object me=this_object();
	send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    长夜漫漫，无心睡眠，我以为只有我睡不着，原来%s你也睡不着啊！难道你还在等圣诞老人的礼物？",me->get_name(),who->get_name()));
}



