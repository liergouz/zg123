#include <ansi.h>
#include <skill.h>
#include <effect.h>
#include <equip.h>
#include <item.h>
inherit "/inh/std/vitaskill";

void create()
{	
	set_skill(630);
	set_skill_type(1);
	set_number(19);
	set_name("���ᵤ����");
	set_skill_level(53);
	set_tool(506);
	set_tili(1);
	set_final("/item/final/91/1833");
	set_skill_temp(0);
	set_master("0");
	set_skill_color(0);
	set_base_rate(75);
        set_product( ([
	"291"	: 	2, 
	"293"	: 	1, 
	"294"	: 	1, 
	"295"	: 	2, 
//	��	: 	0, 
//	��	: 	0,       	     
        ])); 	
        set_count(1);
}
