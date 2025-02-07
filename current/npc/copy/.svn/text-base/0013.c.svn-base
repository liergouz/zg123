#include <npc.h>
#include <ansi.h>
#include <public.h>

inherit OFFICER;

// 函数：获取人物造型
int get_char_picid() { return 2005; }
void do_welcome(string arg);

// 函数：构造处理
void create()
{
	object me=this_object();
        set_name("陵墓邪灵说明");
        set_head_color(0x5a66);
        setup();
}

void do_look(object who)
{
	send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),"大墓室里面的墓穴邪灵乃本陵墓守墓精魂，如有人触怒墓穴邪灵，上层陵墓之内所有未被破坏的兵俑和活着的人都必须群起而攻之。请入墓者自重，切莫触怒墓穴邪灵。\n"ESC"离开");
}

