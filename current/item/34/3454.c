
// �Զ����ɣ�/make/item/make34b

inherit ITEM;
    inherit COMBINED;

// ��������������
//  int get_max_combined() { return 30; }

// ���������촦��
void create()
{
        set_name("ֽǮ");
        set_picid_1(3454);
        set_picid_2(3454);
        set_unit("��");
        set_value(50);
        set_amount(1);
}

// ��������ȡ����
string get_desc() 
{ 
        return "������Ʒ��һ��"; 
}
