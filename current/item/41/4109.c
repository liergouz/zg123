
// �Զ����ɣ�/make/item/make30

inherit ITEM;
    inherit COMBINED;

// ��������������
//  int get_max_combined() { return 30; }

// ������ԭ������
int get_stuff_type() { return 320; }

// ���������촦��
void create()
{
        set_name("��ħ֮��");
        set_picid_1(8915);
        set_picid_2(8915);
        set_unit("��");
        set_value(400);
        set_amount(1);
}

// ��������ȡ����
int get_item_value() {return 1 ;}
int get_item_value_2() {return 1 ;}
string get_desc() 
{ 
        return "�ഫ������ɫ�������µ�Թ��ᾧ��"; 
}
