#include <ansi.h>
#include <skill.h>
#include <effect.h>
#include <equip.h>
#include <item.h>
inherit "/inh/std/vitaskill";

void create()
{	
	set_skill(620);
	set_skill_type(6);
	set_number(304);
	set_name("�ɻ�ʯ����");
	set_skill_level(35);
	set_tool(500);
	set_tili(1);
	set_final("/item/final/71/1035");
	set_skill_temp(1);
	set_master("0");
	set_skill_color(1);
	set_base_rate(75);
        set_product( ([
	"319"	: 	3, 
	"248"	: 	3, 
	"106"	: 	2, 
	"311"	: 	1, 
//	��	: 	0, 
//	��	: 	0,            
        ])); 	
}
