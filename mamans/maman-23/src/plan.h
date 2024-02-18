/* 
 * get file - main(args, agrv)
 *      get line
 *      count lines
 *      parse - word (loop)
 *           check words bin tree if appears (binary search (chapter 3))
 *           if new word then insert
 *           update memory
 *           add line to word node (struct of word node - word + lines appear)
 *       print words hashtable
  */

/*
main(argc, argv)
{
    var file;
    var filecount;
    var filepath;
    FileParser *fparser;
    FileIndex *findex;

    filecount = 0;
    parser = fparser_create();
    findex = findex_create();

    while(filecount++ < argc) {
        filepath = get_next_file(filecount, argv);
 
        if (!check_filepath(filepath) {
            report_invalid_file_err(filepath);
            finalize(findex);
            return EXIT_FAILURE;
        }

        file = fopen(file, "r");
        fparse_to_findex(file, fparser, findex);
        findex_print(stdout, findex);
        fclose(file);
    }

    finalize(parser, findex);
    return EXIT_SUCCESS;
}

void
finalize(FileParser *parser, FileIndex *findex)
{
    fparser_finalize(parser);
    findex_finalize(findex);
}
*/
