
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
        set_name("ճҺ");
        set_picid_1(4007);
        set_picid_2(4007);
        set_value(36);
        set_amount(1);
}

// ��������ȡ����
string get_desc() 
{ 
        return "���ܷ��ڳ�����һ��Һ�壬������Ʒ��"; 
}
