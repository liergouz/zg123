
// �Զ����ɣ�/make/item/make30

inherit ITEM;
    inherit COMBINED;

// ��������ȡװ����ɫ����ɫ
int get_item_color() { return 0; }

// ��������������
//  int get_max_combined() { return 30; }

// ���������촦��
void create()
{
        set_name("����");
        set_picid_1(4060);
        set_picid_2(4060);
        set_value(436);
        set_amount(1);
}

// ��������ȡ����
string get_desc() 
{ 
        return "��������������ź���������Ʒ��"; 
}
