
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit HEAD;

// ��������������
int get_family() { return 2; }

// ���������촦��
void create()
{
        set_name("�ɻ���");
        set_picid_1(6576);
        set_picid_2(6576);

        set_level(45);
        set_value(10300);
        set_max_lasting(8499);
        set("dp", 55);
        set("pp", 33);

        setup();

        set_gender(1);
        set_head_code(43);
}

// ��������ȡ����
string get_desc()
{
        return "�ɻ���";
}
