
// �Զ����ɣ�/make/item/make37a

inherit ITEM;
    inherit COMBINED;

// ��������������
//  int get_max_combined() { return 30; }

// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(3714);
        set_picid_2(3714);
        set_unit("ö");
        set_value(69);
        set_amount(1);
}

// ��������ȡ����
string get_desc() 
{ 
        return "һö�齫��";
}
