
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
        set_name("ǧ�����");
        set_picid_1(4010);
        set_picid_2(4010);
        set_value(51);
        set_amount(1);
}

// ��������ȡ����
string get_desc() 
{ 
        return "һ������ǧ����ٱ�ֲ�������Ʒ��"; 
}
