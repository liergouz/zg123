
// �Զ����ɣ�/make/equip/86b

inherit NECK;

// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(8603);
        set_picid_2(8603);
        set_unit("��");

        set_level(30);
        set_value(4400);
        set_max_lasting(4899);
        set("cp%", 8);
        set("pp", 25);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��������";
}
