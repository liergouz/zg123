#include <effect.h>
inherit ITEM;
inherit COMBINED;

// ��������������
int get_max_combined() { return 30; }

int get_item_color() { return 1; }

// ���������촦��
void create()
{
        set_name("�߹���");
        set_picid_1(98);
        set_picid_2(98);
        set_value(50);
        set_amount(1);
        set_no_give(1);
        set_no_sell(1);  
}

// ��������ȡ����
"18" : "/item/01/0008",
string get_desc() 
{ 
        return "�úñ��������ձ������ã�\n�����ɻ�ȡ�ḻʵ��󽱣�\n���л���õ���Ϸ�еļ�Ʒװ����"; 
}
