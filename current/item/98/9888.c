#include <ansi.h>
#include <item.h>

inherit ITEM;
inherit LEGEND_ITEM;

int iOwner;
int is_souzuo() { return 1;}
int who_can_get() { return iOwner; }
int set_owner(int i) { return iOwner=i; }

// ���������촦��
void create()
{
        set_name( "��ʧ������" );
        set_picid_1(8614);
        set_picid_2(8614);
        set_value(1);
        set_no_give(1);
        set_no_drop(1);
        set_no_sell(1);  
}
// ��������ȡ����
string get_desc() 
{ 
        return "������Ʒ���Ƶ��ϰ�Ҵ����ð�������ɵ�����"; 
}