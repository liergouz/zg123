
// �Զ����ɣ�/make/item/make09

#include <equip.h>
inherit FAMILY_EQUIP;

int get_item_color() { return 1; }
// ���������촦��
void create()
{
        set_name("����");
        set_picid_1(902);
        set_picid_2(902);
        set_unit("��");
        set_family_name("��ɽ");      
        set_max_lasting(1099);
        set_lasting(1099);
        set_no_give(1);
        set_no_drop(1);
        set_no_sell(1);          

}

// ��������ȡ����
string get_desc() 
{ 
        return sprintf("�������� %d��",get_item_level()); 
}

string get_family_desc() 
{ 
	return "��ɽ���������\n����ɽ��ʼ����ȡ��֮�������ƶ��ɡ�\n�Ҽ����ʹ�ÿ�ֱ�Ӵ��ͻ���ɽ��\n��ȴʱ�䣺1����\nÿ��ʹ�û���50��";
}