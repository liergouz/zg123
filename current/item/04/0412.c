#include <item.h>
#include <ansi.h>
inherit ITEM;
inherit COMBINED;


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
        set_name("��ͳ��");
        set_picid_1(9983);
        set_picid_2(9983);
        set_unit("��");
        set_value(50);
        set_amount(1);
}

// ��������ȡ����
string get_desc() 
{
	return "ʥ����ʱ����װ��������ӡ�\n�ɽ���ʥ�����˶һ����";
}

