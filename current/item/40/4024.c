
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
        set_name("�鴮");
        set_picid_1(4024);
        set_picid_2(4024);
        set_value(131);
        set_amount(1);
}

// ��������ȡ����
string get_desc() 
{ 
        return "��������Բ�鴮���ɵ�������������Ʒ��"; 
}
