
// �Զ����ɣ�/make/item/make33

inherit ITEM;
    inherit COMBINED;

// ��������������
//  int get_max_combined() { return 30; }

// ������С��ʶ��
int is_snack() { return 1; }

// ���������촦��
void create()
{
        set_name("������");
        set_picid_1(3324);
        set_picid_2(3324);
        set_unit("��");
        set_value(20);
        set_amount(1);
}

// ��������ȡ����
string get_desc() 
{ 
        return "С�Ե�һ��"; 
}
