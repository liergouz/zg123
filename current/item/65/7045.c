
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit HEAD;

// ��������������
int get_family() { return 7; }

// ���������촦��
void create()
{
        set_name("������");
        set_picid_1(6576);
        set_picid_2(6576);

        set_level(45);
        set_value(15300);
        set_max_lasting(6399);
        set("dp", 34);
        set("pp", 52);

        setup();

        set_gender(1);
        set_head_code(43);
}

// ��������ȡ����
string get_desc()
{
        return "������";
}
