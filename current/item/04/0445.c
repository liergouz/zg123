#include <effect.h>
inherit ITEM;
inherit COMBINED;

// ��������������
int get_max_combined() { return 1; }

int get_item_color() { return 1; }

// ���������촦��
void create()
{
        set_name("����");
        set_picid_1(3567);
        set_picid_2(3567);
        set_value(50);
        set_amount(1);
}

// ��������ȡ����
string get_desc() 
{ 
        return "�ú�ɫ���ɫ˿�߱�֯���򣬿������ҽ�"; 
}
