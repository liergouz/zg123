#include <npc.h>
#include <ansi.h>
#include <public.h>

inherit OFFICER;

// 函数：获取人物造型
int get_char_picid() { return 2006; }
void do_welcome(string arg);

// 函数：构造处理
void create()
{
	object me=this_object();
        set_name("陵墓路标");
        set_head_color(0x5a66);
        setup();
}

void do_look(object who)
{
	send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),"上层陵墓路标：\n    左边道路：往制俑工房\n    右边道路：往墓室区、大墓室；\n"ESC"离开");
}

