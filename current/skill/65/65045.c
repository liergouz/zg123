#include <ansi.h>
#include <skill.h>
#include <effect.h>
#include <equip.h>
#include <item.h>
inherit "/inh/std/vitaskill";

void create()
{	
	set_skill(650);
	set_skill_type(1);
	set_number(45);
	set_name("�����ʯ����");
	set_skill_level(48);
	set_tool(516);
	set_tili(1);
	set_final("/item/stuff/0060");
	set_skill_temp(0);
	set_master("0");
	set_skill_color(0);
	set_base_rate(75);
        set_product( ([
	"83"	: 	1, 
//	��	: 	0, 
//	��	: 	0, 
//	��	: 	0, 
//	��	: 	0, 
//	��	: 	0,       	     
        ])); 	
        set_count(2);
}
