#include <item.h>
#include <ansi.h>
inherit ITEM;
inherit COMBINED;
inherit USABLE;   

// ��������ʹ����Ʒ
int get_item_type_2() { return ITEM_TYPE_2_CON_ALL; }

int get_recover_count() { return 5; }

//ʥ������Ʒ
int is_christmas() { return 1;}

void reset()
{
        if( gone_time( get_drop_time() ) > 7200 )    // 2Сʱ
        {
                remove_from_scene();
                destruct( this_object() );
        }
}
// ���������촦��
void create()
{
        set_name("ʥ����");
        set_picid_1(9982);
        set_picid_2(9982);
        set_unit("ֻ");
        set_value(50);
        set_amount(1);
        set("add_hp", 350);	        
	set("add_mp", 400);	     
}

// ��������ȡ����
string get_desc() 
{
	return "΢ð�������������ʥ����ů�Ļ𼦡�\n�ɽ���ʥ�����˶һ����\n"HIR"������10���ڻظ�350����Ѫ��400�㷨������";
}

// ������ʹ��Ч��
int get_use_effect( object me ) { return "/sys/item/food" ->get_use_effect(me, this_object()); }