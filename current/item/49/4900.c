
// �Զ����ɣ�/make/item/make49
#include <item.h>
inherit ITEM;
    inherit COMBINED;

// ��������������
//  int get_max_combined() { return 30; }

// �������ɶ�Ŀ��ʹ�õ���Ʒ
int get_item_type_2() { return ITEM_TYPE_2_USABLE2; }

// ���������촦��
void create()
{
        set_name("Ǭ����");
        set_picid_1(8700);
        set_picid_2(8700);
        set_value(100);
        set_amount(1);
}

// ��������ȡ����
string get_desc() 
{ 
        return "�ܲ�ץ������������ڲ�ץ����ʱ��ı�����Ʒ��";
}

// ������ʹ��Ч��
int get_use_effect( object me, object who ) { return __FILE__ ->get_use_effect_callout(me, who); }

// ������ʹ��Ч��(���߸���)
int get_use_effect_callout( object me, object who )
{
        int damage;
        object user, owner, *char;      
        int z, x, y, i;  
        "/skill/00/00051"->main(me, who, 0, 0, "");
        return 0;
}