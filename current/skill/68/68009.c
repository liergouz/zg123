#include <ansi.h>
#include <skill.h>
#include <effect.h>
#include <equip.h>
#include <item.h>
inherit "/inh/std/vitaskill";

void create()
{	
	set_skill(680);
	set_skill_type(1);
	set_number(9);
	set_name("�������ӹ�");
	set_skill_level(50);
	set_tool(0);
	set_tili(1);
	set_final("/item/stuff/0295");
	set_skill_temp(0);
	set_master("ҩ���ϰ�");
	set_skill_color(0);
	set_base_rate(100);
        set_product( ([
	"115"	: 	1, 
//		: 	0, 
//		: 	0, 
//		: 	0, 
//		: 	0, 
//		: 	0,            
        ])); 	
}
