#include <ansi.h>
#include <skill.h>
#include <effect.h>
#include <equip.h>
#include <item.h>
inherit "/inh/std/vitaskill";

void create()
{	
	set_skill(620);
	set_skill_type(1);
	set_number(359);
	set_name("����ȭ�׶���");
	set_skill_level(120);
	set_tool(502);
	set_tili(2);
	set_final("/item/final/70/1120");
	set_skill_temp(1);
	set_master("0");
	set_skill_color(1);
	set_base_rate(75);
        set_product( ([
	"272"	: 	3, 
	"309"	: 	1, 
	"42"	: 	1, 
	"54"	: 	5, 
	"94"	: 	3, 
//	��	: 	0,            
        ])); 	
}
