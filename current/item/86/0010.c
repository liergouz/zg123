
// �Զ����ɣ�/make/equip/86b

inherit NECK;

// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(8601);
        set_picid_2(8601);
        set_unit("��");

        set_level(10);
        set_value(1100);
        set_max_lasting(2799);
        set("cp%", 6);
        set("pp", 15);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��������";
}
